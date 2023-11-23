# Sectra Calculator
My solution to the coding problem given by Sectra during the recruitment process
for a masters thesis.

## Initial thoughts

<ul>
    <li>I should be able to use a binary tree to represent expressions.</li>
    <li>It should be possible to use a map to keep track of which nodes are
    "registers".</li>
    <li>I am worried about circular definitions, for example, what happens
    here?</li>

    A add B
    B add A
    A add 1
    print A
</ul>

## Thoughts during development

Due to part of the instructions given by Sectra

> Any name consisting of alphanumeric characters should be allowed as register
> names

there might be some undefined behaviour if we chose a registry name which is
purely numerical, such as "123". What would, for example
    
    123 add 5
    123 add 123
    print 123

print? One could argue that perhaps an alphanumerical string needs to include
<em>both</em> letters and numbers, in which case it is not an issue. My 
implementation will only allow register names starting with a letter.

## Final thoughts

In the end I decided to allow register names starting with a number, but
disallow any name that could be entepreted as a number. For example, "123f"
would be allowed but "123." would not.

### Issues
I did find some unintuitive behaviour with multiplication that I decided was not
worth solving as it is somewhat implied behaviour given the examples given by 
Sectra. The issue is that

    A multiply B
    A add 1
    B add 5

will evaluate to 1, rather than 5. This is because the first line initializes A
as 0, which is then multiplied by B. Now, because the order of operations given
the input is defined as (A * B) + 1, it does not matter that B is later set to
5. This could perhaps be solved, but I am not sure how to do that without
introducing other strange behaviour with regards to order of operations.

Finally, the circular definitions mentioned in the initial thoughts result in a
segmentation fault. I did not put much thought into providing a solution for
that or even gracefully detecting and handling circular definitions.
