#include "ccwindow.h"
#include "style.h"

#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>


CCWindow::CCWindow(QWidget *parent): QMainWindow(parent)
{
    networkManager = new QNetworkAccessManager(this);
    central = new QWidget(this);
    grid = new QGridLayout;

    /**************************************************************************************************************************
     *
     * Text input box
     *
     *************************************************************************************************************************/
    amountEdit = new QLineEdit;
    auto validator = new QDoubleValidator(0.0, 1e9, 2, this);
    validator->setNotation(QDoubleValidator::StandardNotation);
    amountEdit->setValidator(validator);
    amountEdit->setStyleSheet(LineEditStyle);
    amountEdit->setAlignment(Qt::AlignCenter);
    amountEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    amountEdit->setPlaceholderText("Enter amount");
    grid->addWidget(amountEdit, 0, 0, 1, 3);

    /**************************************************************************************************************************
     *
     * Combo boxes
     *
     *************************************************************************************************************************/
    iCombo = new QComboBox;
    oCombo = new QComboBox;
    iCombo->addItems(currencies);
    iCombo->setStyleSheet(ComboBoxStyle);
    oCombo->addItems(currencies);
    oCombo->setStyleSheet(ComboBoxStyle);
    grid->addWidget(iCombo, 1, 0);
    grid->addWidget(oCombo, 1, 2);

    /**************************************************************************************************************************
     *
     * Buttons
     *
     *************************************************************************************************************************/
    switchButton = new QPushButton("⇄");
    switchButton->setStyleSheet(ButtonStyle);

    grid->addWidget(switchButton, 1, 1); // spans two rows vertically

    /**************************************************************************************************************************
     *
     * Output label
     *
     *************************************************************************************************************************/
    resultLabel = new QLabel("");
    resultLabel->setStyleSheet(LabelStyle);
    resultLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    resultLabel->setAlignment(Qt::AlignCenter);
    grid->addWidget(resultLabel, 2, 0, 1, 0);

    /**************************************************************************************************************************
     *
     * Layout setup
     *
     *************************************************************************************************************************/
    central->setLayout(grid);
    setCentralWidget(central);

    setWindowTitle("Currency Converter");
    // setFixedSize(500, 309);
    setMinimumSize(388, 120);
    resize(500, 309);

    /**************************************************************************************************************************
     *
     * Connections
     *
     *************************************************************************************************************************/
    connect(switchButton, &QPushButton::clicked, this, [=]()
    {
        auto iIndex = iCombo->currentIndex();
        iCombo->setCurrentIndex(oCombo->currentIndex());
        oCombo->setCurrentIndex(iIndex);
    });
    fetchRates();
    connect(amountEdit, &QLineEdit::textChanged, this, &CCWindow::convert);
    connect(iCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &CCWindow::convert);
    connect(oCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &CCWindow::convert);

}

void CCWindow::fetchRates()
{
    QString base = "USD";
    QString url = _url.arg(base, apiKey);
    QNetworkReply* reply = networkManager->get(QNetworkRequest(QUrl(url)));

    connect(reply, &QNetworkReply::finished, this, [=]()
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            QJsonObject ratesJson = QJsonDocument::fromJson(reply->readAll())["rates"].toObject();
            for (const QString& currency : currencies)
            {
                if (currency == base)
                {
                    rates[currency] = 1.0;
                }
                else
                {
                    rates[currency] = ratesJson.value(currency).toDouble();
                }
            }
            qDebug() << "Rates:" << rates;
        }
        else
        {
            resultLabel->setText("Failed to load rates.");
        }
        reply->deleteLater();
    });
}

void CCWindow::convert()
{
    QString i = iCombo->currentText();
    QString o = oCombo->currentText();
    double result = amountEdit->text().toDouble() * (rates[o] / rates[i]);
    resultLabel->setText(QString::number(result, 'f', 2));
}

void CCWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    int w = width();
    int h = height();

    int left   = static_cast<int>(w * 0.01);
    int top    = static_cast<int>(h * 0.025);
    int right  = static_cast<int>(w * 0.01);
    int bottom = static_cast<int>(h * 0.05);

    if(auto *layout = centralWidget()->layout())
    {
        layout->setContentsMargins(left, top, right, bottom);
        layout->update();
    }
}

CCWindow::~CCWindow() {}
