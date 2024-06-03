The poster contains a comparison of methods for estimation the likelihood of the parameters for a model specified as a simulator. The results from the poster can be reproduced using R.

The directory contains .ilike files that contain the information required to run algorithms in the ilike package. The files beginning with the prefix "is_" are all set up to estimate the likelihood repeatedly at the same point (via setting up the prior in the parameter space as a Dirac delta on a particular paramneter, and using this as the proposal in an importance sampler). There two examples studied in the poster: a Gaussian example where the likelihood is known analytically (using the word "gauss" in the .ilike file); and a Lotka-Volterra example (using "lv" in the model file). For the Gaussian example, ABC, synthetic likelihood and the new iEnKI-ABC algorithm are used (and each have a separate model file). For the Lotka-Volterra example, ABC, synthetic likelihood, a particle filter, an ensemble Kalman filter, and the new iEnKI-ABC algorithm are used.

To use the files in this directory, follow the instructions below.

1. Install the ilike package using

   ```
   devtools::install_github("richardgeveritt/ilike")
   ```

2. Compile the desired model using, for example,

   ```
   model_abc = ilike::compile("is_abc_lv_XY.ilike")
   ```

3. Call the desired algorithm - in this case an importance sampler as detailed above - in this case estimating the likelihood 100 times. The "model_parameter_list" specifies the values of "p1" and "p2" in the model file (using 10 simulations from the model in the ABC, an setting the ABC tolerance to be 1). The "fixed_parameter_list" specifies the value of another parameter in the model.

   ```
   ilike::importance_sample(model_abc,
                            results_name = "abc_lv_XY_results",
                            number_of_importance_points = 100,
                            model_parameter_list = list(10,1),
                            fixed_parameter_list = list(dt=2),
                            seed = 1)
   ```

4. The output is written to a new directory in the working directory given the name specified in the "results_name" argument (in this case "abc_lv_XY_results"). The output can be imported to an R data frame using, for example:

   ```
   output = ilike::load_smc_output(results_name)
   ```

The results for the poster were generated using different values for the parameters specified in the model files: those specified in the "model_parameter_list" argument.

The code is set up in such a way that it is possible for a user to also use the methods on alternative models. Although these files only show examples of specifying the models in C++, it is also possible to specify the model in R, python or Julia. The likelihood estimates can also be embedded in other algorithms, such as MCMC (which can also be run from the ilike package), but no examples of this are provided in the poster.

Examples of the new iEnKI-ABC likelihood estimator can be found [in this video illustrating the method for a parameter with large likelihood](https://youtu.be/nERovsRTDzI) and [in this video for a parameter with a small likelihood](https://youtu.be/VCgqGTVcnRg). These videos will be linked to via QR codes on the poster.
