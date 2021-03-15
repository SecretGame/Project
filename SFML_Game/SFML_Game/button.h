#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };
class Button
{
private:
    short unsigned buttonState;  //����ʶҹТͧ���� idle,hover,active
    sf::RectangleShape shape;
    sf::Font* font;              //font �ͧ��ͤ�������
    sf::Text text;               //��ͤ���������
    sf::Color textIdleColor;     //�բ�ͤ���ʶҹ� idle
    sf::Color textHoverColor;    //�բ�ͤ���ʶҹ� hover
    sf::Color textActiveColor;   //�բ�ͤ���ʶҹ� active
    sf::Color idleColor;         //�ջ���ʶҹ� idle
    sf::Color hoverColor;        //�ջ���ʶҹ� hover
    sf::Color activeColor;       //�ջ���ʶҹ� active
    sf::Color outlineIdleColor;  //�բͺʶҹ� idle
    sf::Color outlineHoverColor; //�բͺʶҹ� hover
    sf::Color outlineActiveColor;//�բͺʶҹ� active
public:
    Button(float x, float y, float width, float height, sf::Font* font, std::string text, unsigned charractesr_size, sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color, sf::Color idle_color, sf::Color hover_color, sf::Color active_color, sf::Color outline_idle_color = sf::Color::Transparent, sf::Color outline_hover_color = sf::Color::Transparent, sf::Color outline_active_color = sf::Color::Transparent);
    //�ѧ��ѹ
    void update(const sf::Vector2i& mousePosWindow);
    void render(sf::RenderTarget& target);
    bool MousePressCheck[3] = { false,false,false };
    const bool IsMouseRelease() const;
    const bool IsMousePress() const;
    const bool MousePress() const;
};

