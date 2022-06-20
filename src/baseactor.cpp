#include "baseactor.h"
#include "actormgr.h"
#include "random.h"

BaseActor::BaseActor(sf::Shape* shapeRef) : shape(*shapeRef), id(random::int64()) {
    LOGD << "Actor " << std::hex << this->id << " created.";
    this->shape.setOrigin(this->shape.getGlobalBounds().width / 2, this->shape.getGlobalBounds().height / 2);
    ActorMgr::instance()->registerActor(this);
}

BaseActor::~BaseActor() {
    LOGW << "Actor " << std::hex << this->id << " destroyed.";
    delete &this->shape;
    ActorMgr::instance()->deleteActor(this, true);
}
