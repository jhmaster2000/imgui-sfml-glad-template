#include "rectactor.h"
#include "circleactor.h"

class FireBar : public RectActor {
public:
    FireBar(unsigned short numFireballs, unsigned short numBars = 1, float speed = 1.0f, float scale = 50.0f, bool anim = false) : RectActor(sf::Vector2f(scale, scale)) {
        this->setFillColor(sf::Color(0x999999FF));
        for (int i = 0; i < numFireballs * numBars; i++) {
            this->fireballs.push_back(new CircleActor((scale / 5) * 4, 8));
            this->fireballs[i]->setFillColor(sf::Color(0xFF8800FF));
        }
        this->timer = 0;
        this->timerGoingUp = true;
        this->numBars = numBars;
        this->numFireballs = numFireballs;
        this->angle = 0.0f;
        this->radius = scale + (scale / 5);
        this->speed = speed;
        this->anim = anim;
    }
    virtual ~FireBar() {
        for (int i = 0; i < this->fireballs.size(); i++) delete this->fireballs[i];
    }

    void onExecute() override {
        if (this->anim) {
            this->timerGoingUp ? this->timer++: this->timer--;
            if (this->timer == 30) this->timerGoingUp = false;
            if (this->timer == -30) this->timerGoingUp = true;
        } else {
            this->timer = this->speed < 0 ? -30 : 30;
        }
        this->angle += this->speed;
        for (int b = 0; b < this->numBars; b++) {
            for (int f = 0; f < this->numFireballs; f++) {
                const int i = f + b * this->numFireballs;
                const int angle = (this->angle - (f * 5) * (this->timer / 30.0f)) + (360 / this->numBars * b);
                this->fireballs[i]->orbit(this->xy(), this->radius * (f + 1), angle);
                this->fireballs[i]->rotate(-5.0f);
            }
        }
    }

    void onDraw(sf::RenderWindow& window) override {
        BaseActor::onDraw(window);
    }

    float speed;
    float angle;
    float radius;
    bool anim;
    bool timerGoingUp;
    short timer;
    unsigned short numBars;
    unsigned short numFireballs;
    std::vector<CircleActor*> fireballs;
};
