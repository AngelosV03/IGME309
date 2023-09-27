#include "AppClass.h"
void Application::InitVariables(void)
{
	////Change this to your name and email
	m_sProgrammer = "Angelos Veloudos - av1904@rit.edu";
	vector3 v3Position(0.0f, 0.0f, 10.0f);
	vector3 v3Target = ZERO_V3;
	vector3 v3Upward = AXIS_Y;
	m_pCameraMngr->SetPositionTargetAndUpward(v3Position, v3Target, v3Upward);

	//Allocate the memory for the Meshes
	// m_pMesh = new MyMesh();
	// m_pMesh->GenerateCube(1.0f, C_BLACK);
	m_uMeshCount = 46;
	for (uint i = 0; i < m_uMeshCount; ++i)
	{
		MyMesh* pMesh = new MyMesh();
		m_pMeshList.push_back(pMesh);
		m_pMeshList[i]->GenerateCube(1.0f, C_BLACK);
	}
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();

	//Update Entity Manager
	m_pEntityMngr->Update();

	//Add objects to render list
	m_pEntityMngr->AddEntityToRenderList(-1, true);
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//Calculate the model, view and projection matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();

	// m_pMesh->Render(m4Projection, m4View, ToMatrix4(m_qArcBall));
	
	// Create a new timer, create a new clock to store into the timer, and get its delta time
	static float newTimer = 0;
	static uint newClock = m_pSystem->GenClock();
	newTimer += static_cast<float>(m_pSystem->GetDeltaTime(newClock));

	// Drawing all of the meshes
	uint index = 0;
	static float horizontal = -10.0f;
	static vector3 position(horizontal, 0.0f, 0.0f);

	// Calculating positions
	position.x = horizontal + newTimer;
	position.y = glm::cos(glm::radians(newTimer * 60.0f));
	matrix4 matrix4Position = glm::translate(vector3(-5.0f, -3.0f, -15.0f)) * glm::translate(position);

	// Top row
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(3.0f, 0.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(4.0f, 0.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(6.0f, 0.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(7.0f, 0.0f, 0.0f))); ++index;

	// Second row
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(0.0f, 1.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(2.0f, 1.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(8.0f, 1.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(10.0f, 1.0f, 0.0f))); ++index;

	// Third row
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(0.0f, 2.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(2.0f, 2.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(3.0f, 2.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(4.0f, 2.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(5.0f, 2.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(6.0f, 2.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(7.0f, 2.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(8.0f, 2.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(10.0f, 2.0f, 0.0f))); ++index;

	// Fourth row
	for (int increment = 0; increment < 11; ++increment)
	{
		m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(increment, 3.0f, 0.0f))); ++index;
	}

	// Fifth row
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(1.0f, 4.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(2.0f, 4.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(4.0f, 4.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(5.0f, 4.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(6.0f, 4.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(8.0f, 4.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(9.0f, 4.0f, 0.0f))); ++index;

	// Sixth row
	for (int increment = 2; increment < 9; ++increment)
	{
		m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(increment, 5.0f, 0.0f))); ++index;
	}

	// Seventh row
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(3, 6.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(7, 6.0f, 0.0f))); ++index;

	// Bottom row
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(2, 7.0f, 0.0f))); ++index;
	m_pMeshList[index]->Render(m4Projection, m4View, glm::translate(matrix4Position, vector3(8, 7.0f, 0.0f))); ++index;

	// draw a skybox
	m_pModelMngr->AddSkyboxToRenderList();

	//render list call
	m_uRenderCallCount = m_pModelMngr->Render();

	//clear the render list
	m_pModelMngr->ClearRenderList();

	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//Release meshes
	// SafeDelete(m_pMesh);
	std::vector<MyMesh*> m_pMeshList;
	uint uSize = m_pMeshList.size();
	for (uint i = 0; i < uSize; ++i)
	{
		if (m_pMeshList[i] != nullptr)
		{
			delete m_pMeshList[i];
			m_pMeshList[i] = nullptr;
		}
	}

	//release GUI
	ShutdownGUI();
}