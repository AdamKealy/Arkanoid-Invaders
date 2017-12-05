#include "LevelLoader.h"

void operator >> (const YAML::Node& brickNode, BrickData& brick)
{
	brick.m_position.x = brickNode["position"]["x"].as<float>();
	brick.m_position.y = brickNode["position"]["y"].as<float>();
}

//void operator >> (const YAML::Node& backgroundNode, BackgroundData& background)
//{
//	background.m_fileName = backgroundNode["file"].as<std::string>();
//}

void operator >> (const YAML::Node& paddleNode, PaddleData& paddle)
{
	paddle.m_position.x = paddleNode["position"]["x"].as<float>();
	paddle.m_position.y = paddleNode["position"]["y"].as<float>();
}

void operator >> (const YAML::Node& boltNode, BoltData& bolt)
{
	bolt.m_position.x = boltNode["position"]["x"].as<float>();
	bolt.m_position.y = boltNode["position"]["y"].as<float>();
}

void operator >> (const YAML::Node& levelNode, LevelData& level)
{
//	levelNode["background"] >> level.m_background;

	levelNode["paddle"] >> level.m_paddle;
	levelNode["bolt"] >> level.m_bolt;

	const YAML::Node& brickNode = levelNode["bricks"].as<YAML::Node>();
	for (unsigned i = 0; i < brickNode.size(); ++i)
	{
		BrickData brick;
		brickNode[i] >> brick;
		level.m_bricks.push_back(brick);
	}
}

bool LevelLoader::load(int nr, LevelData& level)
{
	std::stringstream ss;
	ss << "./ASSETS/LEVELS/level";
	ss << nr;
	ss << ".yaml";

	try
	{
		YAML::Node baseNode = YAML::LoadFile(ss.str());
		if (baseNode.IsNull())
		{
			std::string message("file: " + ss.str() + " not found");
			throw std::exception(message.c_str());
		}
		baseNode >> level;
	}
	catch (YAML::ParserException& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}
	return true;
}