#include "DiagonalBlaster.h"

void DiagonalBlaster::Update(const GameTime& gameTime)
{
	if (m_cooldown > 0) m_cooldown -= gameTime.GetElapsedTime();
}

void DiagonalBlaster::Fire(TriggerType triggerType)
{
	if (!IsActive()) return;
	if (!CanFire()) return;
	if (!triggerType.Contains(GetTriggerType())) return;

	Projectile* pProjectile = GetProjectile();
	if (!pProjectile) return;

	AudioSample* pAudio = GetFireSound();
	if (pAudio) pAudio->Play();

	pProjectile->Activate(GetPosition(), IsAttachedToPlayer());
	m_cooldown = m_cooldownSeconds;
}