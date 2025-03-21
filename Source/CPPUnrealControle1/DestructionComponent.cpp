#include "DestructionComponent.h"

// Constructeur
UDestructionComponent::UDestructionComponent()
{
	// Activer l'actualisation chaque frame
	PrimaryComponentTick.bCanEverTick = true;

	// Initialiser la portée du rayon
	m_Range = 85.0f;

	// Créer un composant Camera
	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
}

// Fonction appelée lorsque le jeu commence ou que l'acteur est initialisé
void UDestructionComponent::BeginPlay()
{
	Super::BeginPlay(); // Appel à la fonction de base pour initialiser correctement le composant
}

// Fonction appelée chaque frame pour effectuer les opérations du composant
void UDestructionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction); // Appel à la fonction de base pour l'actualisation
}

// Fonction pour effectuer le rayon de destruction
void UDestructionComponent::DestructionBeam()
{
	// Cette fonction peut être utilisée pour initier ou manipuler le rayon, mais pour l'instant elle est vide
}

// Fonction pour effectuer la détection de l'impact du rayon
void UDestructionComponent::DestructionDetection()
{
	FHitResult hit; // Structure pour stocker les informations du rayon

	// Définir le canal de collision utilisé pour le rayon
	ECollisionChannel channel(ECC_GameTraceChannel1);

	// Paramètres du rayon : le nom est vide, 'false' pour ne pas ignorer les collisions avec l'acteur propriétaire
	const FCollisionQueryParams traceParam(FName(TEXT("")), false, GetOwner());

	// Définir la position de départ du rayon (la position de la caméra)
	FVector startPosition = m_Camera->GetComponentLocation();

	// Définir la direction du rayon en fonction de la direction de la caméra
	FVector endPosition = startPosition + m_Camera->GetForwardVector() * m_Range;

	// Effectuer le rayon dans le monde (line trace)
	if (!GetWorld()->LineTraceSingleByChannel(OUT hit, startPosition, endPosition, channel, traceParam))
	{
		// Si aucun impact n'est détecté, réinitialiser l'acteur destructible
		m_Destructible = nullptr;
		return;
	}

	// Récupérer l'acteur touché par le rayon
	AActor* hitActor = hit.GetActor();

	// Si aucun acteur n'est touché, réinitialiser l'acteur destructible
	if (hitActor == nullptr)
	{
		m_Destructible = nullptr;
		return;
	}

	// Vérifier si l'acteur touche implémente l'interface IDestructible
	if (hitActor->GetClass()->ImplementsInterface(UDestructible::StaticClass()))
	{
		// Si l'acteur est destructible, affecter l'acteur destructible et appeler sa fonction DestroyObject
		m_Destructible = hitActor;
		IDestructible::Execute_DestroyObject(m_Destructible); // Appel de la fonction de destruction sur l'acteur
	}
	else
	{
		// Si l'acteur ne supporte pas l'interface IDestructible, réinitialiser l'acteur destructible
		m_Destructible = nullptr;
	}
}
