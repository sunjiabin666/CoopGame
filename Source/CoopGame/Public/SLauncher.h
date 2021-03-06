// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SWeapon.h"
#include "SLauncher.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

/**
 * 
 */
UCLASS()
class COOPGAME_API ASLauncher : public ASWeapon
{
	GENERATED_BODY()
	
protected:
	virtual void Fire() override;
	
	UPROPERTY(EditDefaultsOnly,Category = "Projectile")
	TSubclassOf<AActor>ProjectileClass;

};
