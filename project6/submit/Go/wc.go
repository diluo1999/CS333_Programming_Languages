/*
  CS333 Project 6
  Part II: Selected Language - Go
  Task 1
  Word Counter

  Yixuan Qiu
  Apr 18 2020
*/

package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"regexp"
	"sort"
	"strings"
)

// word-freq pair
type pair struct {
	word string
	freq int
}

func wordCount(words []string) map[string]int {
	// iterate over the slice of words and populate
	// the map with word:frequency pairs
	// (key: word, value: frequency)
	word_freq := make(map[string]int)

	// index is not needed, so use blank identifier _
	for _, word := range words {
		// check if word is in the map
		_, ok := word_freq[word]
		// if true increment frequency
		if ok == true {
			word_freq[word] += 1
		} else {
			// else start frequency at 1
			word_freq[word] = 1
		}
	}
	return word_freq
}

// byFreq implements sort.Interface for []pair based on the freq field
type byFreq []pair

func (a byFreq) Len() int      { return len(a) }
func (a byFreq) Swap(i, j int) { a[i], a[j] = a[j], a[i] }

// descending order
func (a byFreq) Less(i, j int) bool { return a[i].freq > a[j].freq }

func main() {
	bs, err := ioutil.ReadFile("wctest.txt")
	if err != nil {
		log.Fatal(err)
	}
	// change text to all lower case characters
	text := strings.ToLower(string(bs))

	// match whole words, removes punctuation
	reg := regexp.MustCompile(`\p{Ll}+`)
	words := reg.FindAllString(text, -1)

	// a map of word:frequency pairs
	wordMap := wordCount(words)

	// convert the map to a slice of structures for sorting
	// create pointer to an instance of pair
	pws := new(pair)
	structSlice := make([]pair, len(wordMap))

	i := 0
	for key, val := range wordMap {
		pws.freq = val
		pws.word = key
		structSlice[i] = *pws
		i++
	}

	fmt.Println("Sorted by frequency in descending order:")
	// sorting slice of structers by field freq in place
	sort.Sort(byFreq(structSlice))

	n := 20
	// if there are fewer than 20 words in the text
	if n > len(structSlice) {
		n = len(structSlice)
	}

	for j := 0; j < n; j++ {
		fmt.Printf("%s\t\t%d\n", structSlice[j].word, structSlice[j].freq)
	}
}
