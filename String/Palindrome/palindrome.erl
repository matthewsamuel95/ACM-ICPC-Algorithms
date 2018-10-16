-module(palindrome).
-export([palindrome/1]).

palindrome(String) ->
    NormalizedString = normalize(String, ""),
    palindrome(NormalizedString, lists:reverse(NormalizedString)).

palindrome([], []) -> true;
palindrome([ H | Rest ], [ H | Rest2 ]) -> palindrome(Rest, Rest2);
palindrome(_, _) -> false.

normalize([], Result) -> Result;
normalize([ H | Rest ], Result) when H >= $A, H =< $Z -> normalize(Rest, [ H - $A + $a | Result ]);
normalize([ H | Rest ], Result) when (H < $1 orelse H > $9) andalso
                                    (H < $A orelse H > $Z) andalso
                                    (H < $a orelse H > $z) -> normalize(Rest, Result);
normalize([ H | Rest ], Result) -> normalize(Rest, [ H | Result ]).
