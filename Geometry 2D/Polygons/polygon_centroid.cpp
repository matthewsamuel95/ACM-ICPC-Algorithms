pair<vector<point>, vector<point> > polygonCut(vector<point> &p,point A, point B)
{
  vector<point> left, right;
  point intersect;

  for (int i = 0; i < sz(p); ++i)
  {
    point cur = p[i], nxt = p[(i + 1) % sz(p)];
    if ( cp(B-A, cur-A) >= 0)
      right.push_back(cur);

    //NOTE adust intersectSegments should handled AB as line

    if (intersectSegments(A, B, cur, nxt, intersect))
    {
      right.push_back(intersect);
      left.push_back(intersect);
    }
    if ( cp(B-A, cur-A) <= 0)
      left.push_back(cur);
  }

  return make_pair(left, right);
}
