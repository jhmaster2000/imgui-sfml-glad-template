#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include "maths.h"
#include "log.h"

class BaseActor {
protected:
    BaseActor(sf::Shape* shape);

public:
    virtual ~BaseActor();
    virtual void onExecute() {
        return;
    };
    virtual void onDraw(sf::RenderWindow& window) {
        window.draw(this->shape);
    };
    
    float x() const { return this->shape.getPosition().x; }
    float y() const { return this->shape.getPosition().y; }
    const sf::Vector2f& xy() const { return this->shape.getPosition(); }

    void x(float newX) { return this->shape.setPosition(newX, this->y()); }
    void y(float newY) { return this->shape.setPosition(this->x(), newY); }
    void xy(float newX, float newY) { return this->shape.setPosition(newX, newY); }
    void xy(const sf::Vector2f& newXY) { return this->shape.setPosition(newXY); }

    void orbit(float x, float y, float radius, float angleDeg) {
        const float angleRad = degToRad(angleDeg);
        this->shape.setPosition(x + radius * cosf(angleRad), y + radius * sinf(angleRad));
    }
    void orbit(sf::Vector2f point, float radius, float angleDeg) {
        const float angleRad = degToRad(angleDeg);
        this->shape.setPosition(point.x + radius * cosf(angleRad), point.y + radius * sinf(angleRad));
    }

    const unsigned int id;
    sf::Shape& shape;

public: // this->shape proxies
    const sf::Color& getFillColor() const { return this->shape.getFillColor(); };
    sf::FloatRect getGlobalBounds() const { return this->shape.getGlobalBounds(); };
    const sf::Transform& getInverseTransform() const { return this->shape.getInverseTransform(); };
    sf::FloatRect getLocalBounds() const { return this->shape.getLocalBounds(); };
    const sf::Vector2f& getOrigin() const { return this->shape.getOrigin(); };
    const sf::Color& getOutlineColor() const { return this->shape.getOutlineColor(); };
    float getOutlineThickness() const { return this->shape.getOutlineThickness(); };
    virtual sf::Vector2f getPoint(size_t index) const { return this->shape.getPoint(index); };
    virtual size_t getPointCount() const { return this->shape.getPointCount(); };
    const sf::Vector2f& getPosition() const { return this->shape.getPosition(); };
    float getRotation() const { return this->shape.getRotation(); };
    const sf::Vector2f& getScale() const { return this->shape.getScale(); };
    const sf::Texture* getTexture() const { return this->shape.getTexture(); };
    const sf::IntRect& getTextureRect() const { return this->shape.getTextureRect(); };
    const sf::Transform& getTransform() const { return this->shape.getTransform(); };
    void move(const sf::Vector2f& offset) { this->shape.move(offset); };
    void move(float x, float y) { this->shape.move(x, y); };
    void rotate(float angle) { this->shape.rotate(angle); };
    void scale(const sf::Vector2f& factor) { this->shape.scale(factor); };
    void scale(float x, float y) { this->shape.scale(x, y); };
    void setFillColor(const sf::Color& color) { this->shape.setFillColor(color); };
    void setOrigin(const sf::Vector2f& origin) { this->shape.setOrigin(origin); };
    void setOrigin(float x, float y) { this->shape.setOrigin(x, y); };
    void setOutlineColor(const sf::Color& color) { this->shape.setOutlineColor(color); };
    void setOutlineThickness(float thickness) { this->shape.setOutlineThickness(thickness); };
    void setPosition(const sf::Vector2f& position) { this->shape.setPosition(position); };
    void setPosition(float x, float y) { this->shape.setPosition(x, y); };
    void setRotation(float angle) { this->shape.setRotation(angle); };
    void setScale(const sf::Vector2f& factors) { this->shape.setScale(factors); };
    void setScale(float x, float y) { this->shape.setScale(x, y); };
    void setTexture(const sf::Texture *texture, bool resetRect = false) { this->shape.setTexture(texture, resetRect); };
    void setTextureRect(const sf::IntRect &rect) { this->shape.setTextureRect(rect); };
};
