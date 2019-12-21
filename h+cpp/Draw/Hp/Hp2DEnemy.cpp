#include "Hp2DEnemy.h"
#include"../../GameSource/TextureManager.h"

extern TextureManager textureManager;

C_Hp2DEnemy::C_Hp2DEnemy(const D3DXVECTOR3 * ScalPos, const D3DXVECTOR3 * TransPos):C_Hp2D(ScalPos,TransPos)
{
	//�΃o�[
	m_HpTex[1] = { NULL,1,1,NULL,NULL,NULL };
	m_HpTex[1].Tex = textureManager.GetTexture("../GameFolder/Material/Texture/enemyHp.png", m_HpTex[1].Width, m_HpTex[1].Height, NULL);
}
