#include "BombBall.h"

#include "Log.h"
#include "PopAnimation.h"
#include "Scene.h"

class RayCastClosestCallback : public b2RayCastCallback
{
public:
    float ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float fraction) override
    {
        m_body = fixture->GetBody();
        m_fixture = fixture;
        m_point = point;
        m_normal = normal;
        m_fraction = fraction;
        return fraction;
    }

    b2Body* m_body = nullptr;
    b2Fixture* m_fixture = nullptr;
    b2Vec2 m_point;
    b2Vec2 m_normal;
    float m_fraction;
};

void BombBall::OnConstruct()
{
    Ball::OnConstruct();
    m_Texture.loadFromFile("Resources/Sprites/Goon3.png");

    m_collider->OnCollisionEnterCallback([=](CollisionData data)
    {
        if (fired)
        {
            m_Scene->SpawnActor<PopAnimation>(GetPosition())->Play(sf::Color::Red, 1.f, 2.f, 300.f);

            //Explode on contact
            int numRays = 32;
            float blastRadius = 20;
            float blastPower = 50;
            
            b2Vec2 center = {float(m_collider->GetPosition().x / SCALE), float(m_collider->GetPosition().y / SCALE)};
            
            for (int i = 0; i < numRays; i++) {
                float angle = (i / (float)numRays) * 360 * (3.14159f / 180.f);
                b2Vec2 rayDir( sinf(angle), cosf(angle) );
                b2Vec2 rayEnd = center + blastRadius * rayDir;
                    
                //check what this ray hits
                RayCastClosestCallback callback;//basic callback to record body and hit point
                m_Scene->m_world.RayCast(&callback, center, rayEnd);
                if ( callback.m_body )
                {
                      b2Vec2 blastDir = callback.m_point - center;
                      float distance = blastDir.Normalize();
                      //ignore bodies exactly at the blast point - blast direction is undefined
                      if ( distance == 0 )
                          return;
                      float invDistance = 1 / distance;
                      float impulseMag = blastPower * invDistance * invDistance;
                    
                      callback.m_body->ApplyLinearImpulse( impulseMag * blastDir, callback.m_point, true );
                    b2FixtureUserData userData = (b2FixtureUserData)callback.m_fixture->GetUserData();
                    Collider2D* hit = (Collider2D*)userData.pointer;
                    if (hit)
                    {
                        if (hit->GetOwner())
                        {
                            if (hit->GetOwner()->HasAnyTag({"Enemy", "Destructible"}))
                            {
                                if (impulseMag > 5)
                                {
                                    hit->GetOwner()->Destroy();
                                }
                            }
                        }
                        
                      }
                    }
                }
            }

            Destroy();
        
    });
}

void BombBall::Fire(const sf::Vector2f& force, Catapult* catapult, Camera* camera)
{
    Ball::Fire(force, catapult, camera);
}

