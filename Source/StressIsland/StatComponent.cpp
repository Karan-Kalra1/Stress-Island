#include "StatComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"

UStatComponent::UStatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	MaxHealth = 100.f;
	Health = MaxHealth;
}

void UStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// Ensure Health starts clamped
	Health = FMath::Clamp(Health, 0.f, MaxHealth);
}

bool UStatComponent::ChangeHealth(float DamageTaken)
{
	// Equivalent to: Health = Clamp(Health + DamageTaken, 0, MaxHealth)
	Health = FMath::Clamp(Health - DamageTaken, 0.f, MaxHealth);

	// Call OnDamage dispatcher
	OnDamage.Broadcast(Health, DamageTaken);

	// Call IsAlive and return result
	return IsAlive();
}

bool UStatComponent::IsAlive()
{
	if (Health > 0.f)
	{
		return true;
	}
	else
	{
		// Destroy owner when dead (same as Blueprint)
		if (AActor* Owner = GetOwner())
		{
			Owner->Destroy();
		}
		return false;
	}
}
