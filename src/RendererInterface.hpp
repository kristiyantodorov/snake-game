#pragma once

class RendererInterface {
public:
    virtual void drawLine(int x1, int y1, int x2, int y2) = 0;
	virtual void setDrawColor(int r, int g, int b) = 0;
    virtual void clear() = 0;
    virtual void render() = 0;
    virtual void delay(int ms) = 0;
};