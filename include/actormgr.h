#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "baseactor.h"
#include "log.h"

class ActorMgr {
private:
    ActorMgr(): actors({}) {}
    static ActorMgr* thisInstance;

public:
    static ActorMgr* instance() {
        if (ActorMgr::thisInstance == nullptr) ActorMgr::thisInstance = new ActorMgr();
        return ActorMgr::thisInstance;
    }

    void registerActor(BaseActor* actor) {
        this->actors.push_back(actor);
    }

    void deleteActor(BaseActor* actor, bool alreadyDeleted = false) {
        for (int i = 0; i < this->actors.size(); i++) {
            if (this->actors[i] == actor) {
                this->actors.erase(this->actors.begin() + i);
                if (!alreadyDeleted) delete this->actors[i];
                break;
            }
        }
    }

    void drawActors(sf::RenderWindow& window) {
        for (int i = 0; i < this->actors.size(); i++) {
            this->actors[i]->onDraw(window);
        }
    }

    void executeActors() {
        for (int i = 0; i < this->actors.size(); i++) {
            this->actors[i]->onExecute();
        }
    }

    std::vector<BaseActor*> actors;
};
