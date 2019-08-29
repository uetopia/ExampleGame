// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Overlay.h"
#include "Components/CanvasPanel.h"
#include "ILoginFlowManager.h"
#include "Online.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "MyUserWidget.generated.h"

// 4.16 login flow thing
#ifndef UETOPIA_SUBSYSTEM
#define UETOPIA_SUBSYSTEM FName(TEXT("UEtopia"))
#endif

/**
 * 
 */
UCLASS()
class EXAMPLEGAME_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

	// crashes editor
	//virtual void NativeConstruct() override;

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

	//virtual void BeginPlay() override;
	
	
public:

	UMyUserWidget(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "UETOPIA")
		void Login();

	ILoginFlowManager::FOnPopupDismissed OnPopupDismissedUEtopiaDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UButton* ExampleButton;
	UPROPERTY(meta = (BindWidget))
		UOverlay* LoginFlowOverlay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCanvasPanel* panel;

private:
	void FOnPopupDismissed(const TSharedRef<SWidget>& DisplayWidget);
	ILoginFlowManager::FOnPopupDismissed OnDisplayLoginWidget(const TSharedRef<SWidget>& DisplayWidget);
	void OnDismissLoginWidget();
	FReply CancelLoginFlow();

	TSharedPtr<ILoginFlowManager> LoginFlowManager;

	//TSharedPtr<class SWebBrowser> WebBrowserWidget;

	TSharedPtr<SWidget> DisplayWidgetRef;
	
};
