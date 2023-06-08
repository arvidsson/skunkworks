#include "skunk.h"

typedef void (*SceneFunction)(void);

typedef struct Scene {
    SceneFunction Enter;
    SceneFunction Exit;
    SceneFunction Update;
} Scene;

static Scene currentScene;

void TransitionScene(Scenes next)
{
    if (currentScene.Exit != NULL) {
        currentScene.Exit();
    }

    switch (next) {
        case TriangleScene:
            currentScene.Enter = TriangleEnter;
            currentScene.Exit = TriangleExit;
            currentScene.Update = TriangleUpdate;
            break;
    }

    if (currentScene.Enter != NULL) {
        currentScene.Enter();
    }
}

void UpdateScene(void)
{
    if (currentScene.Update != NULL) {
        currentScene.Update();
    }
}
