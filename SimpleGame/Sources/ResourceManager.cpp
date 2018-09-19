#include "ResourceManager.h"

#include <fstream>

#include <Graphics/Sprite.h>

#include <Useful/JSON.hpp>
#include <Useful/OS.h>

ResourceManager::ResourceManager() {
    using json = nlohmann::json;

    nextSpriteNum = 1;

    // Load icons list
    auto config_files = FindFilesRecursive(L"Resources/Icons", L"*.json");
    for (const auto &config_file_path : config_files) {
        std::ifstream config_istr(config_file_path);
        json config;
        config_istr >> config;

        const FileInfo configPathParseResult = ParseFilePath(config_file_path);
        const std::string texturePath = sf::String(configPathParseResult.path + L"/" + configPathParseResult.name + L".png");
        Texture *texture = new Texture(texturePath, config, nextSpriteNum);
        textures.push_back(uptr<Texture>(texture));

        uint32_t numOfNewSprites = texture->GetNumOfSprites();
        for (uint32_t i = 0; i < numOfNewSprites; i++) {
            spritesMap.push_back(texture);
        }

        nextSpriteNum += numOfNewSprites;
    }
}

Sprite ResourceManager::GetSprite(uint32_t id) {
    if (!id || id >= nextSpriteNum) return std::move(Sprite());
    return std::move(spritesMap[id - 1]->GetSprite(id));
}
