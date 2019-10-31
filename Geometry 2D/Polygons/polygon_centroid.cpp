int isInsidePoly(vector<point> p, point p0)
{
  int wn = 0; // the winding number counter
  for (int i = 0; i < sz(p); i++)
  {
    point cur = p[i], nxt = p[(i + 1) % sz(p)];
    if (isPointOnSegment(cur, nxt, p0))
      return true;

    if (cur.Y <= p0.Y) // Upward edge
    {
      if (nxt.Y > p0.Y && cp(nxt-cur, p0-cur) > EPS)
      ++wn;
    }
    else // Downward edge
    {
      if (nxt.Y <= p0.Y && cp(nxt-cur, p0-cur) < -EPS)
      --wn;
    }
  }

  return wn != 0;
}
