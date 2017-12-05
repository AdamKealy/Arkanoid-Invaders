#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "yaml-cpp\yaml.h"

struct BrickData
{
	sf::Vector2f m_position;
};

//struct BackgroundData
//{
//	std::string m_fileName;
//};

struct PaddleData
{
	sf::Vector2f m_position;
};

struct BoltData
{
	sf::Vector2f m_position;
};

struct LevelData
{
//	BackgroundData m_background;
	PaddleData m_paddle;
	BoltData m_bolt;
	std::vector<BrickData> m_bricks;
};

class LevelLoader
{
public:
	LevelLoader() = default;

	static bool load(int nr, LevelData& level);
};