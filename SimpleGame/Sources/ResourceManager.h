#pragma once

#include <vector>

#include <Graphics/Sprite.h>

class ResourceManager {
public:
	ResourceManager();

	Sprite GetSprite(uint32_t id);

private:
	std::vector<uptr<Texture>> textures;
	std::vector<Texture *> spritesMap;
	//std::vector<uptr<Sounds>> sounds;

	uint32_t nextSpriteNum;
};
