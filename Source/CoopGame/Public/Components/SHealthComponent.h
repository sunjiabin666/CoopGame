// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnHealthChangedSignature, USHealthComponent*, OwningHealthComp, float, Health, float, HealthDelta, const class UDamageType*, DamageType, class AController*, InstigatedBy, AActor*, DamageCauser);


UCLASS( ClassGroup=(COOP), meta=(BlueprintSpawnableComponent) )
class COOPGAME_API USHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USHealthComponent();

	UPROPERTY(EditDefaultsOnly, Replicated, BlueprintReadOnly, Category = "HealthComponents")
	uint8 TeamNum;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HealthComponents")
	float DefaultHealth;

	UPROPERTY(ReplicatedUsing=OnRep_Health, BlueprintReadOnly,Category = "HealthComponents")
	float Health;

	bool bIsDead;

	UFUNCTION()
	void OnRep_Health(float OldHealth);

	UFUNCTION()
	void HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

public:
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnHealthChangedSignature OnHealthChanged;

	UFUNCTION(BlueprintCallable, Category = "HealthComponent")
	void Heal(float HealAmount);

	float GetHealth() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "HealthComponent")
	static bool IsFriendly(AActor* A, AActor* B);
};
