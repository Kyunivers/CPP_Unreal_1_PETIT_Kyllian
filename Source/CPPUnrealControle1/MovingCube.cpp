#include "MovingCube.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Math/UnrealMathUtility.h"

AMovingCube::AMovingCube()
{
    PrimaryActorTick.bCanEverTick = true; // Activer Tick()

    // Créer et attacher le composant Mesh
    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    RootComponent = CubeMesh;

    // Charger un cube de base d'Unreal Engine
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (CubeMeshAsset.Succeeded())
    {
        CubeMesh->SetStaticMesh(CubeMeshAsset.Object);
    }
}

void AMovingCube::BeginPlay()
{
    Super::BeginPlay();
    InitialLocation = GetActorLocation(); // Stocke la position de départ
}

void AMovingCube::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Mise à jour du temps
    RunningTime += DeltaTime;

    // Calcul de l'oscillation verticale
    float ZOffset = Amplitude * FMath::Sin(RunningTime * OscillationFrequency * 2 * PI);

    // Calcul du déplacement circulaire
    float XOffset = CircleRadius * FMath::Cos(RunningTime * CircleSpeed * 2 * PI);
    float YOffset = CircleRadius * FMath::Sin(RunningTime * CircleSpeed * 2 * PI);

    // Nouvelle position du cube
    FVector NewLocation = InitialLocation + FVector(XOffset, YOffset, ZOffset);
    SetActorLocation(NewLocation);
}