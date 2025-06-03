#include "..minirt.h"

void	vec_replace(t_vec *dest, t_vec src)
{
	dest->x = src.x;
	dest->y = src.y;
	dest->z = src.z;
}

//scales a vector.
t_vec	vec_scalarmult(t_vec *vec, float scalar)
{
	t_vec	ret;

	ret.x = vec->x * scalar;
	ret.x = vec->y * scalar;
	ret.x = vec->z * scalar;
	return (ret);
}

//The sum of two vec a and b, 
//is a new vec starting at a and ending at b's end.
t_vec	vec_sum(t_vec *vec1, t_vec *vec2)
{
	t_vec	ret;

	ret.x = vec1->x + vec2->x;
	ret.y = vec1->y + vec2->y;
	ret.z = vec1->z + vec2->z;
	return (ret);
}

//returns the angle between two vectors. (unit?; 0 = 90`)
//(ret = ||a||*||b||*cosT)(T=arccos(a.b/||a||*||b||))
float	vec_dotproduct(t_vec *vec1, t_vec *vec2)
{
	float	ret;

	ret = vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z;
	return (ret);
}
