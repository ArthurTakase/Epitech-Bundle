#include <Server/RType.hpp>
#include <iostream>
#include <map>

/**
 * It creates a new entity, adds a behavior component to it, and returns the
 * entity's id
 *
 * @return The id of the entity that was created.
 */
int RType::createSpawner() noexcept
{
    auto spawner = entityManager_.newEntity();

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&](Entity* entity) {
        const static json patterns = JsonTools::getPatternsFromFile();

        if (nbEnemyAlive > 0) { return; }

        nbEnemyAlive = 0;
        int  wave_id = rand() % patterns.size();
        auto pattern = patterns[wave_id];
        createEntityWave(pattern);
    }});

    spawner->addComponent(behavior);
    return spawner->getId();
}

/**
 * It creates a map of function pointers to member functions of the class, and then
 * calls the function pointed to by the map's value, using the map's key as the
 * argument
 *
 * @param type the type of enemy to create
 * @param positions a json array of json arrays of 2 ints.
 */
void RType::createEntityWave(json::array_t pattern) noexcept
{
    std::map<std::string, int (RType::*)(int, int)> creation = {{"basic", &RType::createBasicEnemy},
        {"curve", &RType::createCurvedEnemy},
        {"powerup", &RType::createRandomPowerUp},
        {"boss", &RType::createBoss}};
    for (auto& info : pattern) { (this->*(creation[info["type"]]))(info["positions"][0], info["positions"][1]); }
}
