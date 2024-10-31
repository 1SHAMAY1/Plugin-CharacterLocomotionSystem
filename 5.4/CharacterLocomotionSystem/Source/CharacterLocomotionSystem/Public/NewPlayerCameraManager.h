/**
 * Copyright (c) 2024 [SHANKHARAJ DATTA]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software, known as the "Soft Character Locomotion System," and associated
 * documentation files (including user manuals, API documentation, and readme files)
 * (the "Software"), to deal in the Software without restriction, including without
 * limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * EXCEPTION: The animations included with this Software (if any) are not covered
 * under this license and may not be used, copied, modified, merged, published,
 * distributed, sublicensed, or sold without express permission from [SHANKHARAJ DATTA].
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "NewPlayerCameraManager.generated.h"

/**
 * Player Camera Manager with support for smooth transitions during crouch, slide, prone and vault  states.
 */
UCLASS()
class CHARACTERLOCOMOTIONSYSTEM_API ANewPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()

public:
	ANewPlayerCameraManager();
	/*
	 * Duration for smooth transitions of the camera when the character changes
	 * between crouching, proning, and sliding states. This value determines how
	 * long it takes for the camera to smoothly blend to the new position, enhancing
	 * the player's visual experience by avoiding abrupt changes in view.
	 * Measured in seconds.
	 */
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Blend Durations")
	float SmoothBlendDuration;


protected:
	float SmoothBlendTime;

	virtual void UpdateViewTarget(FTViewTarget& OutVT, float DeltaTime) override;
};

