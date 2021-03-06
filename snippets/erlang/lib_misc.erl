-module(lib_misc).

-export([for/3, pythag/1, qsort/1, perm/1, max/2, count_characters/1]).

% for loop
for(Max, Max, F) -> [F(Max)];
for(I, Max, F) -> [F(I) | for(I + 1, Max, F)].

% quick sort implementation
qsort([]) -> [];
qsort([Pivot | T]) ->
    qsort([X || X <- T, X < Pivot]) ++
      [Pivot] ++ qsort([X || X <- T, X >= Pivot]).

% misc
pythag(N) ->
    [{A, B, C}
     || A <- lists:seq(1, N), B <- lists:seq(1, N),
	C <- lists:seq(1, N), A + B + C =< N,
	A * A + B * B =:= C * C].

% simple permutation implementation
perm([]) -> [[]];
perm(L) -> [[H | T] || H <- L, T <- perm(L -- [H])].

max(X,Y) when X > Y -> X;
max(_,Y) -> Y.


% https://stackoverflow.com/questions/23106543/illegal-pattern-in-map-of-erlang
count_characters(Str) ->
    count_characters(Str, #{}).
count_characters([H|T], X) ->
    case maps:is_key(H, X) of
        false -> count_characters(T, X#{H=>1});
        true -> #{H := Counter } = X,
            count_characters(T, X#{H:= Counter + 1})
        end;
    count_characters([], X) ->
    X.