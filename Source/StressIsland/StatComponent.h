#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatComponent.generated.h"

/**
 * Event dispatcher equivalent to Blueprint OnDamage
 * Sends current Health and DamageTaken
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnDamageSignature,
	float, Health,
	float, DamageTaken
);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class STRESSISLAND_API UStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UStatComponent();

protected:
	virtual void BeginPlay() override;

public:

	/* ========== VARIABLES ========== */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MaxHealth;

	/* ========== EVENT DISPATCHER ========== */

	UPROPERTY(BlueprintAssignable, Category = "Stats")
	FOnDamageSignature OnDamage;

	/* ========== FUNCTIONS ========== */

	UFUNCTION(BlueprintCallable, Category = "Stats")
	bool IsAlive();

	UFUNCTION(BlueprintCallable, Category = "Stats")
	bool ChangeHealth(float DamageTaken);
};
