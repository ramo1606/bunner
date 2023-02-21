#include "ActiveRow.h"
#include "ResourceManager.h"

#include <random>

ActiveRow::ActiveRow(MoverType childType, std::vector<int>& dxs, std::string& baseImage, int index, float y)
	: Row(baseImage, index, y),
	m_ChildType(childType)
{
	m_Dx = dxs[GetRandomValue(0, dxs.size() - 1)];	// Randomly choose a direction for cars/logs to move

    // Populate the row with child objects(cars or logs).Without this, the row would initially be empty.
    m_Pos.x = -WIDTH * 0.5f - 70;
    while (m_Pos.x < WIDTH * 0.5f + 70)
    {
        m_Pos.x += GetRandomValue(240, 480);
        Vector2 pos = { WIDTH * 0.5f + (m_Dx > 0 ? m_Pos.x : -m_Pos.x), 0.f };
        //SmartActor* newChild = ResourceManager::getCar(m_Dx, pos);
        //m_Children.push_back(newChild);
    }
}

void ActiveRow::update()
{
    Row::update();

    //m_Children

    m_Timer -= 1;

    if (m_Timer < 0)
    {
        Vector2 pos = { (m_Dx < 0) ? WIDTH + 70.f : -70.f, 0.f };
        //SmartActor* newChild = ResourceManager::getCar(m_Dx, pos);
        //m_Children.push_back(newChild)

        /*
        * 240 is minimum distance between the start of one child object and the start of the next, assuming its
        * speed is 1. If the speed is 2, they can occur twice as frequently without risk of overlapping with
        * each other.The maximum distance is double the minimum distance(1 + random value of 1)
        */
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dist(0, 1);

        m_Timer = (1 + dist(gen)) * (240 / std::abs(m_Dx));
    }
}
