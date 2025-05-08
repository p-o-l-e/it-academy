#include <map>

namespace Shapes 
{
    enum class Shape
    {
        CIRCLE,
        SQUARE,
        RECTANGLE,

        COUNT
    };

    inline const std::map<Shape, const char*> shape_map_default
    {
        { Shape::CIRCLE,    "Circle"    },
        { Shape::SQUARE,    "Square"    },
        { Shape::RECTANGLE, "Rectangle" } 
    };
    
    void printShape(const Shape&, const std::map<Shape, const char*>& map = shape_map_default);
    void printType(const char*,  const std::map<Shape, const char*>& map = shape_map_default);
    
} // Namespace Shapes