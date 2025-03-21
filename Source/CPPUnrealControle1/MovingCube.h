

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingCube.generated.h"

UCLASS()
class CPPUNREALCONTROLE1_API AMovingCube : public AActor
{
    GENERATED_BODY()

public:
    AMovingCube();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    // Composant Mesh du cube
    UPROPERTY(VisibleAnywhere, Category = "Mesh")
    UStaticMeshComponent* CubeMesh;

    // Position initiale du cube
    FVector InitialLocation;

    // Variables pour l'oscillation verticale
    UPROPERTY(EditAnywhere, Category = "Oscillation")
    float Amplitude = 50.0f;

    UPROPERTY(EditAnywhere, Category = "Oscillation")
    float OscillationFrequency = 1.0f; // Fréquence de l'oscillation verticale

    // Variables pour le mouvement circulaire
    UPROPERTY(EditAnywhere, Category = "Mouvement Circulaire")
    float CircleRadius = 100.0f;

    UPROPERTY(EditAnywhere, Category = "Mouvement Circulaire")
    float CircleSpeed = 1.0f; // Contrôle la vitesse de rotation

    // Temps accumulé
    float RunningTime = 0.0f;
};