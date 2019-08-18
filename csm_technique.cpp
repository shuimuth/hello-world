/*

	Copyright 2011 Etay Meiri

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ogldev_util.h"
#include "csm_technique.h"



CSMTechnique::CSMTechnique()
{
}

bool CSMTechnique::Init()
{
    if (!Technique::Init()) {
        return false;
    }

    if (!AddShader(GL_VERTEX_SHADER, "Shaders/csm.vs")) {
        return false;
    }

    if (!AddShader(GL_FRAGMENT_SHADER, "Shaders/csm.fs")) {
        return false;
    }

    if (!Finalize()) {
        return false;
    }

    m_WVPLocation = GetUniformLocation("gWVP");

    if (m_WVPLocation == INVALID_UNIFORM_LOCATION) {        
        return false;
    }

    return true;
}

void CSMTechnique::SetWVP(const Matrix4f& WVP)
{
    glUniformMatrix4fv(m_WVPLocation, 1, GL_TRUE, (const GLfloat*)WVP.m);
}


BGTechnique::BGTechnique()
{
}

bool BGTechnique::Init()
{
    if (!Technique::Init()) {
        return false;
    }

    if (!AddShader(GL_VERTEX_SHADER, "Shaders/background.vs")) {
        return false;
    }

    if (!AddShader(GL_FRAGMENT_SHADER, "Shaders/background.fs")) {
        return false;
    }

    if (!Finalize()) {
        return false;
    }

    m_VLocation = GetUniformLocation("view");

    if (m_VLocation == INVALID_UNIFORM_LOCATION) {        
        return false;
    }

    m_PLocation = GetUniformLocation("projection");

    if (m_PLocation == INVALID_UNIFORM_LOCATION) {        
        return false;
    }

    m_CubeLocation = GetUniformLocation("environmentMap");

    if (m_CubeLocation == INVALID_UNIFORM_LOCATION) {        
        return false;
    }
    return true;
}

void BGTechnique::SetView(const Matrix4f& view)
{
    glUniformMatrix4fv(m_VLocation, 1, GL_TRUE, (const GLfloat*)view.m);
}

void BGTechnique::SetProj(const Matrix4f& proj)
{
    glUniformMatrix4fv(m_PLocation, 1, GL_TRUE, (const GLfloat*)proj.m);
}

void BGTechnique::SetCubeMapUnit(uint TextureUnit){
    glUniform1i(m_CubeLocation, TextureUnit);
}