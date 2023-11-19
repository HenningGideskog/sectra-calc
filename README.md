# Sectra Calculator
My solution to the coding problem given by Sectra during the recruitment process
for a masters thesis.

## Initial thoughts

<ul>
    <li>I should be able to use a binary tree to represent expressions.</li>
    <li>It should be possible to use a map to keep track of which nodes are
    "registers".</li>
    <li>I am worried about circular definitions, for example, what happens here?
    <ol>
        <li>A add B</li>
        <li>B add A</li>
        <li>A add 1</li>
        <li>print A</li>
    </ol>
    </li>
</ul>
