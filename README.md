# Sectra Calculator
My solution to the coding problem given by Sectra during the recruitment process
for a masters thesis.

## Initial thoughts

<ul>
    <li>I should be able to use a binary tree to represent expressions.</li>
    <li>It should be possible to use a map to keep track of which nodes are
    "registers".</li>
    <li>I am worried about circular definitions, for example, what happens here?
            A add B
            B add A
            A add 1
            print A
    </li>
</ul>

## Thoughts during development

Due to part of the instructions given by Sectra

> Any name consisting of alphanumeric characters should be allower as register
> names

there might be some undefined behaviour if we chose a registry name which is
purely numerical, such as "123". What would, for example
    
    123 add 5
    123 add 123
    print 123

print? One could argue that perhaps an alphanumerical string needs to include
<em>both</em> letters and numbers, in which case it is not an issue. My 
implementation will only allow register names starting with a letter.
