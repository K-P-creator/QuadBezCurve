// Cubic Curve will draw a simple cubic bezier curve that goes through two points and pulls towards TWO
// The start and end points are guarenteed points of intersection, while the control points are not. 

#ifndef CUBIC_CURVE_HPP
#define CUBIC_CURVE_HPP

#include <SFML/Graphics.hpp>


namespace sf {
	class CubicCurve : public sf::Drawable, public sf::Transformable
	{
	public:
		CubicCurve(const sf::Vector2f startPosition, const sf::Vector2f endPosition,
			const sf::Vector2f controlPositionOne, const sf::Vector2f controlPositionTwo,
			const unsigned int vertexCount = 10, const float thickness = 0.1f) noexcept;

		void setColor(const sf::Color);

		void setVertexCount(const unsigned int count);

		void setPoints(const sf::Vector2f startPosition, const sf::Vector2f endPosition,
			const sf::Vector2f controlPositionOne, const sf::Vector2f controlPositionTwo);

		void setThickness(const float thickness);

	private:
		sf::VertexArray m_vertices;

		float m_thickness;
		bool isThick;

		sf::Vector2f m_startPosition;
		sf::Vector2f m_endPosition;
		sf::Vector2f m_controlPositionOne;
		sf::Vector2f m_controlPositionTwo;

		unsigned int m_vertexCount;
		sf::Color m_color;

		void updateVertices();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}



inline void sf::CubicCurve::setColor(const sf::Color color)
{
	m_color = color;
	for (unsigned int i = 0; i < m_vertexCount; i++)
	{
		m_vertices[i].color = m_color;
	}
}

inline void sf::CubicCurve::setVertexCount(const unsigned int count)
{
	m_vertexCount = count;
	m_vertices.resize(m_vertexCount);
	updateVertices();
}

inline void sf::CubicCurve::setPoints(const sf::Vector2f startPosition, const sf::Vector2f endPosition,
	const sf::Vector2f controlPositionOne, const sf::Vector2f controlPositionTwo)
{
	m_startPosition = startPosition;
	m_endPosition = endPosition;
	m_controlPositionOne = controlPositionOne;
	m_controlPositionTwo = controlPositionTwo;
	updateVertices();
}

inline void sf::CubicCurve::setThickness(const float thickness)
{
	m_thickness = thickness;
	if (m_thickness > 0.1f) isThick = true;
	else isThick = false;
}

#endif // CUBIC_CURVE_HPP