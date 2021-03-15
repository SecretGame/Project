#include "Button.h"
Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, unsigned charractesr_size, sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color, sf::Color idle_color, sf::Color hover_color, sf::Color active_color, sf::Color outline_idle_color, sf::Color outline_hover_color, sf::Color outline_active_color)
{
    this->buttonState = BTN_IDLE;
    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(idle_color);
    this->shape.setOutlineThickness(1.f);
    this->shape.setOutlineColor(outline_idle_color);
    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(text_idle_color);
    this->text.setCharacterSize(charractesr_size);
    this->text.setPosition(
        this->shape.getPosition().x +
        (this->shape.getGlobalBounds().width / 2.f) -
        this->text.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y +
        (this->shape.getGlobalBounds().height / 2.f) -
        this->text.getGlobalBounds().height / 2.f
    );
    //กำหนดสีข้อความ
    this->textIdleColor = text_idle_color;
    this->textHoverColor = text_hover_color;
    this->textActiveColor = text_active_color;
    //กำหนดสีปุ่ม
    this->idleColor = idle_color;
    this->hoverColor = hover_color;
    this->activeColor = active_color;
    //กำหนดสีขอบ
    this->outlineIdleColor = outline_idle_color;
    this->outlineHoverColor = outline_hover_color;
    this->outlineActiveColor = outline_active_color;
}

// Pressed
const bool Button::MousePress() const
{
    if (this->buttonState == button_states::BTN_ACTIVE)
        return true;

    return false;
}

const bool Button::IsMousePress() const
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return true;
    }
    else return false;
}

const bool Button::IsMouseRelease() const
{
    if (!(sf::Mouse::isButtonPressed(sf::Mouse::Left)))
    {
        return true;
    }
    else return false;
}

void Button::update(const sf::Vector2i& mousePosWindow)
{
    //Idle
    this->buttonState = button_states::BTN_IDLE;

    //Hover
    if (this->shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosWindow)))
    {
        this->buttonState = BTN_HOVER;

        if (this->IsMousePress())
        {
            MousePressCheck[0] = true;
            MousePressCheck[1] = false;
        }
        if (this->IsMousePress())MousePressCheck[1] = true;

        if (MousePressCheck[0] and MousePressCheck[1])
        {
            this->buttonState = button_states::BTN_ACTIVE;
            MousePressCheck[0] = false;
            MousePressCheck[1] = false;
        }
    }
    else {
        MousePressCheck[0] = false;
        MousePressCheck[1] = false;
    }

    switch (this->buttonState)
    {
    case BTN_IDLE:
        this->shape.setFillColor(this->idleColor);
        this->text.setFillColor(this->textIdleColor);
        this->shape.setOutlineColor(this->outlineIdleColor);
        break;
    case BTN_HOVER:
        this->shape.setFillColor(this->hoverColor);
        this->text.setFillColor(this->textHoverColor);
        this->shape.setOutlineColor(this->outlineHoverColor);
        break;
    case BTN_ACTIVE:
        this->shape.setFillColor(this->activeColor);
        this->text.setFillColor(this->textActiveColor);
        this->shape.setOutlineColor(this->outlineActiveColor);
        break;
    default:
        this->shape.setFillColor(sf::Color::Red);
        this->text.setFillColor(sf::Color::Blue);
        this->shape.setOutlineColor(sf::Color::Green);
        break;
    }
}
void Button::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
    target.draw(this->text);
}