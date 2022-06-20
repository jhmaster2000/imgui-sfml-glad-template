#include "rectactor.h"
#include "circleactor.h"

class FireBar : public RectActor {
public:
    FireBar(unsigned short numFireballs, unsigned short numBars = 1, float scale = 50.0f) : RectActor(sf::Vector2f(scale, scale)) {
        this->setFillColor(sf::Color(0x999999FF));
        for (int i = 0; i < numFireballs * numBars; i++) {
            this->fireballs.push_back(new CircleActor((scale / 5) * 4, 8));
            this->fireballs[i]->setFillColor(sf::Color(0xFF8800FF));
        }
        this->numBars = numBars;
        this->numFireballs = numFireballs;
        this->angle = 0.0f;
        this->radius = scale + (scale / 5);
    }
    virtual ~FireBar() {
        for (int i = 0; i < this->fireballs.size(); i++) delete this->fireballs[i];
    }

    void onExecute() override {
        this->angle += 2.0f;
        for (int b = 0; b < this->numBars; b++) {
            for (int f = 0; f < this->numFireballs; f++) {
                const int i = f + b * this->numFireballs;
                this->fireballs[i]->rotate(-5.0f);
                this->fireballs[i]->orbit(this->xy(), this->radius * (f + 1), (this->angle - f * 5) + (360 / this->numBars) * b);
            }
        }
    }

    void onDraw(sf::RenderWindow& window) override {
        BaseActor::onDraw(window);
    }

    float angle;
    float radius;
    unsigned short numBars;
    unsigned short numFireballs;
    std::vector<CircleActor*> fireballs;
};
