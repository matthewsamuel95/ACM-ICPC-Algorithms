point polygonCenteriod(vector<point> points)
{
  double x = 0, y = 0, a = 0, c;
  for(int i = 0; i < points.size(); ++i)
  {
    int j = (i + 1) % sz(points);
    c = cp(points[i], points[j]), a += c;
    x += (points[i].X + points[j].X) * c;
    y += (points[i].Y + points[j].Y) * c;
  }

  if (dcmp(a, 0) == 0)
    return (points[0] + points.back()) * 0.5;

  a /= 2;
  x /= 6 * a;
  y /= 6 * a;

  // fix x,y -0.0
  return point(x, y);
}
