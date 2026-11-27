#include "pch.h"

#include "OrbitCamera.h"
#include "CameraManager.h"

TEST(OrbitCameraTests, C01_InitialPosition)
{
    Vector3 target{ 0.0f, 0.0f, 0.0f };
    OrbitCamera camera(target, 10.0f, 0.25f);

    Camera3D result = camera.GetCamera();

    EXPECT_NEAR(result.target.x, target.x, 0.0001f);
    EXPECT_NEAR(result.target.y, target.y, 0.0001f);
    EXPECT_NEAR(result.target.z, target.z, 0.0001f);
    EXPECT_NEAR(result.position.z, 10.0f, 0.0001f);
}

TEST(OrbitCameraTests, C02_NoRotationWithoutRightClick)
{
    OrbitCamera camera(Vector3{ 0.0f, 0.0f, 0.0f }, 10.0f, 0.25f);

    Camera3D before = camera.GetCamera();

    InputController::InputSnapshot snapshot{};
    snapshot.right_mouse_button_down = false;
    snapshot.mouse_delta = Vector2{ 100.0f, 50.0f };

    camera.Update(0.016f, snapshot);

    Camera3D after = camera.GetCamera();

    EXPECT_NEAR(after.position.x, before.position.x, 0.0001f);
    EXPECT_NEAR(after.position.y, before.position.y, 0.0001f);
    EXPECT_NEAR(after.position.z, before.position.z, 0.0001f);
}

TEST(OrbitCameraTests, C03_RotationWithRightClick)
{
    OrbitCamera camera(Vector3{ 0.0f, 0.0f, 0.0f }, 10.0f, 0.25f);

    Camera3D before = camera.GetCamera();

    InputController::InputSnapshot snapshot{};
    snapshot.right_mouse_button_down = true;
    snapshot.mouse_delta = Vector2{ 100.0f, 0.0f };

    camera.Update(0.016f, snapshot);

    Camera3D after = camera.GetCamera();

    EXPECT_NE(before.position.x, after.position.x);
    EXPECT_NE(before.position.z, after.position.z);
}

TEST(OrbitCameraTests, C04_ZoomIn)
{
    OrbitCamera camera(Vector3{ 0.0f, 0.0f, 0.0f }, 10.0f, 0.25f);

    InputController::InputSnapshot snapshot{};
    snapshot.mouse_wheel = 2.0f;

    camera.Update(0.016f, snapshot);

    Camera3D result = camera.GetCamera();

    float dx = result.position.x - result.target.x;
    float dy = result.position.y - result.target.y;
    float dz = result.position.z - result.target.z;

    float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

    EXPECT_NEAR(distance, 8.0f, 0.0001f);
}

TEST(OrbitCameraTests, C05_ZoomOut)
{
    OrbitCamera camera(Vector3{ 0.0f, 0.0f, 0.0f }, 10.0f, 0.25f);

    InputController::InputSnapshot snapshot{};
    snapshot.mouse_wheel = -2.0f;

    camera.Update(0.016f, snapshot);

    Camera3D result = camera.GetCamera();
    float dx = result.position.x - result.target.x;
    float dy = result.position.y - result.target.y;
    float dz = result.position.z - result.target.z;

    float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

    EXPECT_NEAR(distance, 12.0f, 0.0001f);
}

TEST(OrbitCameraTests, C06_MinimumZoomDistance)
{
    OrbitCamera camera(Vector3{ 0.0f, 0.0f, 0.0f }, 10.0f, 0.25f);

    InputController::InputSnapshot snapshot{};
    snapshot.mouse_wheel = 100.0f;

    camera.Update(0.016f, snapshot);

    Camera3D result = camera.GetCamera();

    float dx = result.position.x - result.target.x;
    float dy = result.position.y - result.target.y;
    float dz = result.position.z - result.target.z;

    float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

    EXPECT_NEAR(distance, 4.0f, 0.0001f);
}

TEST(OrbitCameraTests, C07_MaximumZoomDistance)
{
    OrbitCamera camera(Vector3{ 0.0f, 0.0f, 0.0f }, 10.0f, 0.25f);

    InputController::InputSnapshot snapshot{};
    snapshot.mouse_wheel = -100.0f;

    camera.Update(0.016f, snapshot);

    Camera3D result = camera.GetCamera();

    float dx = result.position.x - result.target.x;
    float dy = result.position.y - result.target.y;
    float dz = result.position.z - result.target.z;

    float distance = std::sqrt(dx * dx + dy * dy + dz * dz);

    EXPECT_NEAR(distance, 25.0f, 0.0001f);
}

class TestCameraController : public ICameraController
{
public:
    int updateCount = 0;

    void Update(float _delta_time, const InputController::InputSnapshot& _snapshot) override
    {
        updateCount++;
    }

    Camera3D GetCamera() const override
    {
        return Camera3D{};
    }
};

TEST(CameraManagerTests, C08_UpdateController)
{
    CameraManager manager;
    TestCameraController controller;

    manager.SetController(controller);

    InputController::InputSnapshot snapshot{};

    manager.Update(0.016f, snapshot);

    EXPECT_EQ(controller.updateCount, 1);
}

TEST(CameraManagerTests, C09_GetCameraFromController)
{
    CameraManager manager;
    OrbitCamera camera(Vector3{ 1.0f, 2.0f, 3.0f }, 10.0f, 0.25f);

    manager.SetController(camera);

    Camera3D expected = camera.GetCamera();
    Camera3D result = manager.GetCamera();

    EXPECT_NEAR(result.target.x, expected.target.x, 0.0001f);
    EXPECT_NEAR(result.target.y, expected.target.y, 0.0001f);
    EXPECT_NEAR(result.target.z, expected.target.z, 0.0001f);

    EXPECT_NEAR(result.position.x, expected.position.x, 0.0001f);
    EXPECT_NEAR(result.position.y, expected.position.y, 0.0001f);
    EXPECT_NEAR(result.position.z, expected.position.z, 0.0001f);
}
