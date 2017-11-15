#include "Light.h"
#include "stdafx.h"

//////////////////////////////////////
//			Light.cpp				//
//	���� ������ Ȱ���ϴ� ����ó����	//
//	��Ƶ� cpp�Դϴ�.					//
//	1. ū �ؿ� ���� �Լ�				//
//		- ���� ũ��360�� ȸ�� �մϴ�. //
//	2. ���� ���� �� Ȱ��Ǵ� ����		//
//		- �÷��̾ ����ٴմϴ�.	//
//									//
//////////////////////////////////////

void Light_Sun()
{
	GLfloat AmbientLight[] = { ambientL, ambientL, ambientL, ambientL };//�ֺ� ����
	GLfloat DiffuseLight[] = { diffuseL, diffuseL, diffuseL, diffuseL };//��� �ݻ� ����
	GLfloat SpecularLight[] = { specularL, specularL, specularL, specularL };//�ſ�ݻ� ����
	GLfloat lightPos[] = { -28, 0, 0, 1 };
	GLfloat specref[] = { 1,1,1,1 };
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);

	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	if (Bool_Sun == true)
	{
		glPushMatrix();
		{
			glColor3f(4, 4, 0);
			glTranslated(-75, 0, 0);
			glTranslated(0, -1, 0);
			glTranslated(0, 0, 0);
			glutSolidSphere(10, 50, 50);
		}
		glPopMatrix();

		glEnable(GL_LIGHT0);
		glEnable(GL_COLOR_MATERIAL);
	}
	else
	{
		glDisable(GL_LIGHT0);
	}
}

void Light_Lantern()
{
	GLfloat Direction[] = { 0, 0, 1 };//�ֺ� ����
	GLfloat lightPos[] = { 0, 1, 0, 1 };
	GLfloat specref[] = { 1,1,1,1 };

	GLfloat AmbientLight[] = { ambientL, ambientL, ambientL, ambientL };//�ֺ� ����
	GLfloat DiffuseLight[] = { diffuseL, diffuseL, diffuseL, diffuseL };//��� �ݻ� ����
	GLfloat SpecularLight[] = { specularL, specularL, specularL, specularL };//�ſ�ݻ� ����

	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, Direction);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.01);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, cutoff);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.9);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.1);

	glLightfv(GL_LIGHT1, GL_AMBIENT, AmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, DiffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SpecularLight);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos);

	glEnable(GL_COLOR_MATERIAL); // ����... ��ü�� �⺻���� �����°Ű���..!
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	if (Bool_Sun == false)
	{
		glEnable(GL_LIGHT1);
	}
	else
	{
		glDisable(GL_LIGHT1);
	}
}