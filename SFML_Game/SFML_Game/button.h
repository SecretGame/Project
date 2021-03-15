#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };
class Button
{
private:
    short unsigned buttonState;  //ใช้เก็บสถานะของปุ่ม idle,hover,active
    sf::RectangleShape shape;
    sf::Font* font;              //font ของข้อความปุ่ม
    sf::Text text;               //ข้อความบนปุ่ม
    sf::Color textIdleColor;     //สีข้อความสถานะ idle
    sf::Color textHoverColor;    //สีข้อความสถานะ hover
    sf::Color textActiveColor;   //สีข้อความสถานะ active
    sf::Color idleColor;         //สีปุ่มสถานะ idle
    sf::Color hoverColor;        //สีปุ่มสถานะ hover
    sf::Color activeColor;       //สีปุ่มสถานะ active
    sf::Color outlineIdleColor;  //สีขอบสถานะ idle
    sf::Color outlineHoverColor; //สีขอบสถานะ hover
    sf::Color outlineActiveColor;//สีขอบสถานะ active
public:
    Button(float x, float y, float width, float height, sf::Font* font, std::string text, unsigned charractesr_size, sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color, sf::Color idle_color, sf::Color hover_color, sf::Color active_color, sf::Color outline_idle_color = sf::Color::Transparent, sf::Color outline_hover_color = sf::Color::Transparent, sf::Color outline_active_color = sf::Color::Transparent);
    //ฟังก์ชัน
    void update(const sf::Vector2i& mousePosWindow);
    void render(sf::RenderTarget& target);
    bool MousePressCheck[3] = { false,false,false };
    const bool IsMouseRelease() const;
    const bool IsMousePress() const;
    const bool MousePress() const;
};

