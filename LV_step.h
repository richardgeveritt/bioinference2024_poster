// Adapted from Darren Wilkinson's smfsb R package.
arma::colvec my_stepLVc(RandomNumberGenerator &rng,
                        double X,
                        double Y,
                        const arma::colvec &theta,
                        double t0,
                        double dt)
{
  double t = t0;
  double termt = t + dt;
  arma::colvec x(2);
  x[0] = X;
  x[1] = Y;
  while (1==1)
  {
    double h1 = theta[0]*x[0];
    double h2 = theta[1]*x[0]*x[1];
    double h3 = theta[2]*x[1];
    double h0 = h1 + h2 + h3;
    if ((h0<1e-10)||(x[0]>=1000000))
      t=1e99;
    else
      t+=rexp(rng,h0);
    if (t>=termt)
    {
      return x;
    }
    double u = runif(rng);
    if (u<h1/h0)
      x[0]+=1.0;
    else if (u<(h1+h2)/h0) {
      x[0]-=1.0; x[1]+=1.0;
    } else
      x[1]-=1.0;
  }
}
