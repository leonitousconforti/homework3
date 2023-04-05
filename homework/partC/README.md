# Part C - Lightrail

This part assumes you already have knowledge of Google Tests and how to write unit tests. If you
don't, you should do part A first.

This part will be similar to the previous with a couple more differences:

* There are, yet again, more mutants
* Instead of testing a single independent class, you must test a full interconnected system

## Provided Files

We have not provided the actual source files for the lightrail system, but we have provided the header
files (they're in
the `include` folder).  Use the header files to figure out functionality of the Lightrail system and how
it should be called.

Additionally, we have provided the compiled object files of the system, which
you can use to locally run your programs. You may assume that the provided object files are the correct version of the
code.

We have also provided a template `main.cc` file that shows example usage of the lightrail system. Feel free
to edit this file as much as you want (you won't be submitting it anyways). You can compile and
run the code you write in `main.cc` with:

(*code templates assume you are in the current directory*)

```bash
make

./lightrail
```

Use the `main.cc` file to clarify any questions or confusions about the expected behavior of the
lightrail system.

Finally, we have provided a template `lightrail_unittest.cc` file. Similar to the part B, You will have to fill this file out
with your own unit tests and submit it to Gradescope. At any time, you can run your tests against the
correct version of the code with:

```bash
make

./lightrail_unittest
```

🚨 **ATTENTION** 🚨

Again, since it is being run against the *correct* version of the code, all of your tests should *pass*. If
your tests do not *pass* when you run it locally, then that means that your tests are not correctly using
the lightrail system. Again, you can use the `main.cc` file to understand how to correctly use the system and
test stuff out there.

🚨🚨🚨🚨🚨🚨


## **Submission**

Submit your work by uploading the `lightrail_unittest.cc` file to Gradescope. You can upload as many times
as you want until the deadline. Note that if your tests do not *pass* against the *correct* version of
the code (which you can test locally), you will not receive any points for catching the mutants.

### Notes

* Again, the submitted filename should be exactly `lightrail_unittest.cc`
