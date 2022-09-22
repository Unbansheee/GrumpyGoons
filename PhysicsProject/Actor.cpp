#include "Actor.h"
#include "Scene.h"

void Actor::FixedUpdate(float deltaTime)
{
    if (!m_shouldUpdate)
        return;
}

void Actor::Update(float deltaTime)
{
    if (!m_shouldUpdate)
        return;
    
}

void Actor::Draw()
{
    if (!m_isVisible)
        return;
}

void Actor::SetRenderPriority(int priority)
{
    m_DrawPriority = priority;
}

int Actor::GetRenderPriority() const
{
    return m_DrawPriority;
}

void Actor::SetIsVisible(bool isVisible)
{
    m_isVisible = isVisible;
}

bool Actor::GetIsVisible() const
{
    return m_isVisible;
}

void Actor::SetShouldUpdate(bool shouldUpdate)
{
    m_shouldUpdate = shouldUpdate;
}

bool Actor::GetShouldUpdate() const
{
    return m_shouldUpdate;
}

void Actor::SetScene(Scene* scene)
{
    m_Scene = scene;
}

Scene* Actor::GetScene() const
{
    return m_Scene;
}

void Actor::SetPosition(const sf::Vector2f& position)
{
    m_position = position;
}

sf::Vector2f Actor::GetPosition() const
{
    return m_position;
}

void Actor::SetRotation(float angle)
{
    m_rotation = angle;
}

float Actor::GetRotation() const
{
    return m_rotation;
}

bool Actor::HasTag(const std::string& tag) const
{
    return std::find(m_tags.begin(), m_tags.end(), tag) != m_tags.end();
    
}

bool Actor::HasAnyTag(const std::vector<std::string>& tags) const
{
    for (const auto& tag : tags)
    {
        if (HasTag(tag))
            return true;
    }
    return false;
    
}

bool Actor::HasAllTags(const std::vector<std::string>& tags) const
{
    for (const auto& tag : tags)
    {
        if (!HasTag(tag))
            return false;
    }
    return true;
    
}

void Actor::AddTag(const std::string& tag)
{
    if (!HasTag(tag))
        m_tags.push_back(tag);
    
}

void Actor::AddTags(const std::vector<std::string>& tags)
{
    for (const auto& tag : tags)
    {
        AddTag(tag);
    }
    
}

void Actor::RemoveTag(const std::string& tag)
{
    auto it = std::find(m_tags.begin(), m_tags.end(), tag);
    if (it != m_tags.end())
        m_tags.erase(it);
    
}

void Actor::RemoveAllTags()
{
    m_tags.clear();
    
}

std::string Actor::GetTagsString()
{
    std::string str;
    for (auto i : m_tags)
    {
        str.append(i + ",\n");
    }
    return str;
}

void Actor::Destroy()
{
    m_Scene->DestroyActor(this);
}
