// Fill out your copyright notice in the Description page of Project Settings.

#include "MyUserWidget.h"
#include "OnlineSubsystemUtils.h"
#include "ILoginFlowModule.h"


// Crashes Editor
/*
void UMyUserWidget::NativeConstruct()
{
Super::NativeConstruct();
}
*/



/*
void UMyUserWidget::BeginPlay() {
Super::BeginPlay();
if (hudWidgetClass) {
// the player controller should be constructed by now so we can get a reference to it
hudWidget = CreateWidget<UUserWidget>(this->GetOwningPlayerController(), this->hudWidgetClass);
hudWidget->AddToViewport();
}
}
*/


// Does not compile:  "already has a body"
/*
UMyUserWidget::UMyUserWidget(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}
*/

TSharedRef<SWidget> UMyUserWidget::RebuildWidget()
{
	auto Result = Super::RebuildWidget();

	/*
	UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());

	if (!RootWidget)
	{
	RootWidget = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootWidget"));
	// we need the slot
	UCanvasPanelSlot* RootWidgetSlot = Cast<UCanvasPanelSlot>(RootWidget->Slot);
	if (RootWidgetSlot)
	{
	// make fullscreen and scale fullscreen on resize
	RootWidgetSlot->SetAnchors(FAnchors(0.f, 0.f, 1.f, 1.f));
	RootWidgetSlot->SetOffsets(FMargin(0.f, 0.f));
	}
	WidgetTree->RootWidget = RootWidget;
	}

	LoginFlowOverlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("Login Flow Overlay")); // The second parameter is the name and is optional.

	RootWidget->AddChild(LoginFlowOverlay);
	*/
	

	return Result;
}


UMyUserWidget::UMyUserWidget(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	// crashes editor
	//RebuildWidget();
}

void UMyUserWidget::FOnPopupDismissed(const TSharedRef<SWidget>& DisplayWidget)
{
	// create a login flow UI which contains the slate widget or native host widget blueprint implementable
	///...
	//return a FOnPopupDismissed delegate that the underlying system will call when the screen is closed for any reason.
}

ILoginFlowManager::FOnPopupDismissed UMyUserWidget::OnDisplayLoginWidget(const TSharedRef<SWidget>& DisplayWidget)
{
	// create a login flow UI which contains the slate widget or native host widget blueprint implementable
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] OnDisplayLoginWidget"));

	//GEngine->GameViewport->AddViewportWidgetContent(DisplayWidget);

	TSharedRef<SOverlay> SlateRootOverlay = StaticCastSharedRef<SOverlay>(LoginFlowOverlay->TakeWidget());

	SlateRootOverlay->AddSlot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			DisplayWidget
		];

	//TSharedRef < SWidget > LoginFlowSWidget = LoginFlowOverlay->TakeWidget();
	//SOverlay* LoginFlowSOverlay = Cast<SOverlay>(LoginFlowSWidget);
	//LoginFlowSOverlay->AddSlot(1).AttachWidget(DisplayWidget);

	//MyMainMenu->

	// scrollbox isn't working becuase we have a Swidget not a Uwidget
	/*
	if (UScrollBox* ScrollBox = Cast<UScrollBox>(MyMainMenu->GetWidgetFromName("loginFlowContainer")))
	{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] OnDisplayLoginWidget found loginFlowContainer"));
	ScrollBox->AddChild(DisplayWidget);
	ScrollBox->
	}
	else
	{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] OnDisplayLoginWidget DID NOT FIND loginFlowContainer"));
	// Can't find the scroll widget, wrong name maybe, or a widget with that name is not a scrollwidget
	//ItemWidgetsBox = nullptr;
	}
	*/




	// found this here:
	// https://answers.unrealengine.com/questions/388469/extending-swebbrowser.html
	//WebBrowserWidget = SNew(SWebBrowser)
	//	.InitialURL("http://www.google.com")
	//	.ShowControls(false)
	//	.SupportsTransparency(false);

	//return WebBrowserWidget.ToSharedRef();

	// store the reference to the widget
	DisplayWidgetRef = DisplayWidget;

	//return a FOnPopupDismissed delegate that the underlying system will call when the screen is closed for any reason.
	return ILoginFlowManager::FOnPopupDismissed::CreateUObject(this, &UMyUserWidget::OnDismissLoginWidget);
}

void UMyUserWidget::OnDismissLoginWidget()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [UMyUserWidget] OnDismissLoginWidget"));
	// Widget dismissed by login flow or possibly game related Blueprint code
	// For slate typically
	//Overlay->RemoveSlot(LoginFlow.ToSharedRef());
	//GEngine->GameViewport->RemoveViewportWidgetContent(DisplayWidgetRef->AsShared());
}

FReply UMyUserWidget::CancelLoginFlow()
{
	// Blueprint callable if outer UI has way to shutdown login flow
	//if (LoginFlowManager.IsValid())
	//{
	//	LoginFlowManager->CancelLoginFlow();
	//}
	return FReply::Handled();
}

void UMyUserWidget::Login()
{
	UE_LOG(LogTemp, Log, TEXT("[UETOPIA] [AMyPlayerController] Login"));


	// Initialize the login flow UI code



	UWorld* World = GetWorld();
	FName FacebookIdentifier = Online::GetUtils()->GetOnlineIdentifier(World, FACEBOOK_SUBSYSTEM);
	FName GoogleIdentifier = Online::GetUtils()->GetOnlineIdentifier(World, GOOGLE_SUBSYSTEM);
	FName UEtopiaIdentifier = Online::GetUtils()->GetOnlineIdentifier(World, UETOPIA_SUBSYSTEM);




	ILoginFlowModule& LoginFlowModule = ILoginFlowModule::Get();

	LoginFlowManager = LoginFlowModule.CreateLoginFlowManager();

	//if (!LoginFlowManager->AddLoginFlow(FacebookIdentifier, ILoginFlowManager::FOnDisplayPopup::CreateUObject(this, &AMyPlayerController::OnDisplayLoginWidget)))
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("No Facebook subsystem configured. It will be unavailable"));
	//}
	//if (!LoginFlowManager->AddLoginFlow(GoogleIdentifier, ILoginFlowManager::FOnDisplayPopup::CreateUObject(this, &AMyPlayerController::OnDisplayLoginWidget)))
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("No Google subsystem configured. It will be unavailable"));
	//}

	// This changed in 4.20
	// Now the 3rd argument is for On Account Create
	// WHich we don't use.  FOR NOW
	// Just returning the same delegate for now.
	if (!LoginFlowManager->AddLoginFlow(UEtopiaIdentifier, ILoginFlowManager::FOnDisplayPopup::CreateUObject(this, &UMyUserWidget::OnDisplayLoginWidget), ILoginFlowManager::FOnDisplayPopup::CreateUObject(this, &UMyUserWidget::OnDisplayLoginWidget), true))

	{
		UE_LOG(LogTemp, Warning, TEXT("No UEtopia subsystem configured. It will be unavailable"));
	}

	const auto OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		const auto IdentityInterface = OnlineSub->GetIdentityInterface();
		if (IdentityInterface.IsValid())
		{
			FOnlineAccountCredentials* Credentials = new FOnlineAccountCredentials("InType", "InId", "InToken");
			IdentityInterface->Login(0, *Credentials);
		}
	}



}