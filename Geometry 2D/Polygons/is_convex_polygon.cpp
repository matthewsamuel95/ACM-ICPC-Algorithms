bool isConvexPolygon(vector<point> &p)
{
  p.push_back(p[0]);
  p.push_back(p[1]);
  int sign = ccw(p[0], p[1], p[2]);
  bool ok = true;
  for (int i = 1; ok && i < sz(p) - 2; i++)
  {
    if (ccw(p[i], p[i + 1], p[i + 2]) != sign)
    ok = false;
  }
  p.pop_back(), p.pop_back();
  return ok;
}

int ccw(point a, point b, point c)
{
  point v1(b - a), v2(c - a);
  double t = cp(v1, v2);
  if (t > +EPS)return +1;
  if (t < -EPS)return -1;
  if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
  return -1;
  if (norm(v1) < norm(v2) - EPS)
  return +1;
  return 0;
}
