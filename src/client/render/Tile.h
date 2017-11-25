// Generated by dia2code
#ifndef RENDER__TILE__H
#define RENDER__TILE__H


namespace render {

  /// class Tile - 
  class Tile {
    // Attributes
  protected:
    int x     = 672;
    int y     = 0;
    int width     = 96;
    int height     = 96;
    // Operations
  public:
    Tile ();
    Tile (int x, int y, int w, int h);
    // Setters and Getters
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);
  };

};

#endif
