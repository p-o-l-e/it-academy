#ifndef CCWINDOW_H
#define CCWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <QGridLayout>

class CCWindow: public QMainWindow
{
    private:
        Q_OBJECT
        const QStringList currencies = { "USD", "EUR", "BYN" };
        QMap<QString, double> rates;
        const QString apiKey = "d73e95aab0666ebe765b5cf3";
        const QString _url = "https://open.er-api.com/v6/latest/%1?apikey=%2";
        QNetworkAccessManager *networkManager;
        QGridLayout *grid;
        QLineEdit *amountEdit;
        QComboBox *iCombo;
        QComboBox *oCombo;
        QPushButton *switchButton;
        QLabel *resultLabel;
        QWidget *central;
        void fetchRates();
        void convert();

    public:
        void resizeEvent(QResizeEvent*) override;
        CCWindow(QWidget *parent = nullptr);
        ~CCWindow();
};
#endif // CCWINDOW_H
