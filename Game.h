
#include <d3dx9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 )


#pragma once
class Game
{
public:

	LPDIRECT3D9         g_pD3D = NULL; // Used to create the D3DDevice
	LPDIRECT3DDEVICE9   g_pd3dDevice = NULL; // Our rendering device

	LPD3DXMESH          g_pMesh = NULL; // Our mesh object in sysmem
	D3DMATERIAL9*       g_pMeshMaterials = NULL; // Materials for our mesh
	LPDIRECT3DTEXTURE9* g_pMeshTextures = NULL; // Textures for our mesh
	DWORD               g_dwNumMaterials = 0L;   // Number of mesh materials

	Game();
	HRESULT InitD3D(HWND hWnd);
	HRESULT InitGeometry();
	bool Initialize(HWND hWnd);
	VOID Cleanup();
	VOID Render();

private:
	VOID SetupMatrices();
	~Game();
};

