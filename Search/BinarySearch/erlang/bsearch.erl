-module(bsearch).
-export([binary_search/2]).

binary_search(Element, List) -> binary_search(Element, List, 0, length(List) - 1).

binary_search(_, _, Lower, Higher) when Higher < Lower -> {notfound, null};
binary_search(Element, List, Lower, Higher) ->
    Mid = (Lower + Higher) div 2,
    case lists:nth(Mid, List) of
        Element -> {ok, Mid - 1};
        Another when Another < Element ->
            binary_search(Element, List, Mid + 1, Higher);
        Another when Another > Element ->
            binary_search(Element, List, Lower, Mid - 1)
    end.

