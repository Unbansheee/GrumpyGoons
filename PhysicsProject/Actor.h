#pragma once
#include <functional>

#include "Renderer.h"
#include "TimedCallback.h"
#include "MathUtils.h"

class Scene;

class Actor
{
public:
    const double SCALE = 30.0;

    Actor() = default;
    virtual ~Actor() = default;

    virtual void OnConstruct() = 0;
    virtual void BeginPlay() = 0;
    virtual void FixedUpdate(float deltaTime);
    virtual void Update(float deltaTime);
    virtual void Draw();
    virtual void OnDestroy() = 0;

    void SetRenderPriority(int priority);
    int GetRenderPriority() const;

    void SetIsVisible(bool isVisible);
    bool GetIsVisible() const;

    void SetShouldUpdate(bool shouldUpdate);
    bool GetShouldUpdate() const;

    void SetScene(Scene* scene);
    Scene* GetScene() const;

    void SetPosition(const sf::Vector2f& position);
    sf::Vector2f GetPosition() const;

    void SetRotation(float angle);
    float GetRotation() const;

    bool IsMarkedForDestroy() const {return m_markedForDestroy;}
    void MarkForDestroy() {m_markedForDestroy = true;}

    bool HasTag(const std::string& tag) const;
    bool HasAnyTag(const std::vector<std::string>& tags) const;
    bool HasAllTags(const std::vector<std::string>& tags) const;
    void AddTag(const std::string& tag);
    void AddTags(const std::vector<std::string>& tags);
    void RemoveTag(const std::string& tag);
    void RemoveAllTags();
    const std::vector<std::string>& GetTags() { return m_tags; }
    std::string GetTagsString();

    void SetUpdatePriority(int priority) { m_updatePriority = priority; }
    int GetUpdatePriority() const { return m_updatePriority; };
    
    void Destroy();

    template <typename T>
    bool Is()
    {
        return Cast<T>();
    }

    template <typename T>
    T* Cast()
    {
        return dynamic_cast<T*>(this);
    }
    
protected:
    std::vector<std::string> m_tags;
    
    sf::Vector2f m_position;
    float m_rotation = 0.0f;

    bool m_markedForDestroy = false;
    int m_updatePriority = 0;
    int m_DrawPriority = 0;
    bool m_isVisible = true;
    bool m_shouldUpdate = true;
    Scene* m_Scene = nullptr;
};
