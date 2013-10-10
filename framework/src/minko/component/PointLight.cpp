/*
Copyright (c) 2013 Aerys

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "PointLight.hpp"

#include "minko/math/Vector4.hpp"
#include "minko/math/Matrix4x4.hpp"

using namespace minko;
using namespace minko::math;
using namespace minko::component;

PointLight::PointLight(float attenuationDist):
	AbstractDiscreteLight("pointLights"),
	_worldPosition(Vector3::create(0.0f, 0.0f, 0.0f)),
	_attenuationDistance(Vector2::create(0.0f, 0.0f))
{
	diffuse(1.f);
	specular(1.f);

	attenuationDistance(attenuationDist);
	data()->set("position", _worldPosition);
}

void
PointLight::updateModelToWorldMatrix(std::shared_ptr<math::Matrix4x4> modelToWorld)
{
	modelToWorld->copyTranslation(_worldPosition);
}

void
PointLight::attenuationDistance(float value)
{
	_attenuationDistance->setTo(value > 1e-6f ? value : -1.0f, 0.0f);
	data()->set("attenuationDistance", _attenuationDistance);
}
